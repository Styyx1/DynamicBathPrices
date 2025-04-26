#include "settings.h"
#include "cellchangeevent.h"

static void ChangeGlobalOnLoad() {
    Settings::Forms::bath_price_global->value = std::clamp(Settings::Forms::room_cost_global->value / 2.0f, 20.0f, Settings::Forms::room_cost_global->value);
    logs::info("[ONLOAD] {} is now: {}", Settings::Forms::bath_price_global->GetFormEditorID(), Settings::Forms::bath_price_global->value);
}

void Listener(SKSE::MessagingInterface::Message *message) noexcept
{
    if (message->type == SKSE::MessagingInterface::kDataLoaded)
    {
        Settings::Forms::LoadForms();
        Events::RegisterEvents();
    }
    if (message->type == SKSE::MessagingInterface::kPostLoadGame) {
        ChangeGlobalOnLoad();
    }
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse);

    if (const auto messaging{SKSE::GetMessagingInterface()}; !messaging->RegisterListener(Listener))
    {
        return false;
    }

	return true;
}
