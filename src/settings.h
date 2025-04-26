#pragma once

namespace Settings {
	namespace Constants {
		constexpr const char* bath_mod = "InnBath.esp";
		const int bath_price_global_ID = 0x814;
		//vanilla room cost global
		//the improved innkeeper mod changes this value based on various conditions
		const int room_cost_global_ID = 0x9CC98;
	}
	namespace Values {
	}
	class Forms {
	public:
		static void LoadForms() {
			
			auto dh = RE::TESDataHandler::GetSingleton();

			bath_price_global = dh->LookupForm<RE::TESGlobal>(Constants::bath_price_global_ID, Constants::bath_mod);
			room_cost_global = dh->LookupForm<RE::TESGlobal>(Constants::room_cost_global_ID, "Skyrim.esm");

		};
		static inline RE::TESGlobal* bath_price_global{ nullptr };
		static inline RE::TESGlobal* room_cost_global{ nullptr };

	};
}
