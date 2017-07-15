-- file : config.lua
local module = {}

module.SSID = {}  
module.SSID["WIFIID"] = "PASSWORD"

module.HOST = "test.mosquito.org"  
module.PORT = 1883
module.ID = node.chipid()

module.ENDPOINT = "opengate/"
return module  
