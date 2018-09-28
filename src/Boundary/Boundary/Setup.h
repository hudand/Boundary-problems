#pragma once

namespace di = boost::di;

auto BuildInjector() {

	std::filesystem::path path = GetSettingsPath() / "Settings.json";

	return di::make_injector(
		di::bind<JsonConfigurationManager>.to(path));
} 
