#pragma once

namespace di = boost::di;

auto BuildInjector() {

	return di::make_injector(
		di::bind<JsonConfigurationManager>.to(GetSettingsPath() / "Settings.json"));
} 
