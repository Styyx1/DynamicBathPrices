#include "settings.h"
#include "cellchangeevent.h"

void Listener(SKSE::MessagingInterface::Message *message) noexcept
{
    if (message->type == SKSE::MessagingInterface::kDataLoaded)
    {
        Settings::Forms::LoadForms();
        Events::RegisterEvents();
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
