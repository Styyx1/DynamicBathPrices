#include "cellchangeevent.h"

namespace Events {

	void RegisterEvents()
	{
		auto cellHandler = CellChangeEvent::GetSingleton();
		cellHandler->RegisterCellEvent();
	}

	EventResult CellChangeEvent::ProcessEvent(const RE::TESCellFullyLoadedEvent* a_event, RE::BSTEventSource<RE::TESCellFullyLoadedEvent>* a_eventSource)
	{
		if(!a_event)
			return EventResult::kContinue;
		if(!a_event->cell)
			return EventResult::kContinue;

		if (!a_event->cell->GetLocation() || !a_event->cell->GetLocation()->HasKeywordByEditorID("LocTypeInn")) {
			return EventResult::kContinue;
		}

		if (Settings::Forms::bath_price_global && Settings::Forms::room_cost_global) {
			logs::info("{} is an inn, adjusting globals", a_event->cell->GetName());
			AdjustGlobal();
		}

		return EventResult::kContinue;
	}
	void CellChangeEvent::RegisterCellEvent()
	{
		RE::ScriptEventSourceHolder *eventHolder = RE::ScriptEventSourceHolder::GetSingleton();
		eventHolder->AddEventSink(CellChangeEvent::GetSingleton());
		logs::info("Registered for {}", typeid(RE::TESCellFullyLoadedEvent).name());
	}
	void CellChangeEvent::AdjustGlobal()
	{
		std::jthread{ [=] {
			std::this_thread::sleep_for(2.0s);
			SKSE::GetTaskInterface()->AddTask([=] {
				Settings::Forms::bath_price_global->value = std::clamp(Settings::Forms::room_cost_global->value / 2.0f, 20.0f, Settings::Forms::room_cost_global->value);
				logs::info("{} is now: {}", Settings::Forms::bath_price_global->GetFormEditorID(), Settings::Forms::bath_price_global->value);
				});
			}}.detach();
	}
	
}