#pragma once

#include "settings.h"

using EventResult = RE::BSEventNotifyControl;

namespace Events {

	void RegisterEvents();

	class CellChangeEvent : public REX::Singleton<CellChangeEvent>,
		public RE::BSTEventSink<RE::TESCellFullyLoadedEvent>
	{
		EventResult ProcessEvent(const RE::TESCellFullyLoadedEvent *a_event, [[maybe_unused]] RE::BSTEventSource<RE::TESCellFullyLoadedEvent> *a_eventSource) override;
	public:
		void RegisterCellEvent();
		void AdjustGlobal();

	};
}
