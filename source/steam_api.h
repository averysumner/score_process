// steam_api.h
// Copyright (C) averysumner
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef STEAM_API_H_
#define STEAM_API_H_

#include <vector>
#include <string>
#include <map>

#include "json/single_include/nlohmann/json.hpp"
#include "cpp-httplib/httplib.h"

namespace score_process {

class SteamAPI {
 public:
  SteamAPI();
  ~SteamAPI();
  nlohmann::json Request(std::string url, std::map<std::string, std::string> arguments);
  nlohmann::json GetUsers(std::vector<std::string> ids);
 private:
  std::string base_url_ = "http://api.steampowered.com";
  httplib::Client* client_ = nullptr;
};

} // namespace score_process

#endif // STEAM_API_H_