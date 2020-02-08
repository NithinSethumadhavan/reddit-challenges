#pragma once

#include "HTTPRequest.hpp"
#include "json.hpp"

#include <fstream>

namespace currencyFetch
{
  using json = nlohmann::json;

  constexpr auto requestURL = "http://data.fixer.io/api/latest?access_key=8c3a940b4fe75a1ccb6ada8ec16ab081&symbols=EUR,INR";
  constexpr auto fileName = "/Users/Nithin/bin/Currency.json";

  double getCurrency()
  {
    std::string jsonData;
    try
    {
      http::Request request(requestURL);
      const http::Response getResponse = request.send("GET");
      jsonData = std::string(getResponse.body.begin(), getResponse.body.end());
      std::ofstream saveFile(fileName);
      saveFile << jsonData;
    }
    catch (const std::exception& e)
    {
      std::ifstream saveFile(fileName);
      saveFile >> jsonData;
    }
      json j = json::parse(jsonData);
      return j["rates"]["INR"];
  }
}//namespace currencyFetch


