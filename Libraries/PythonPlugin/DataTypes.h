
#pragma once

#include <dcapi\PluginDefs.h>

#include <string>

struct UserDataExt
{
	std::string nick;
	std::string hubHint;
	std::string cid;
	dcptr_t object;
	uint32_t sid;
	ProtocolType protocol;
	bool isOp;
};

struct HubDataExt
{
	std::string url;
	std::string ip;
	dcptr_t object;
	uint16_t port;
	ProtocolType protocol;
	bool isOp;
	bool isSecure;	
};

struct QueueDataExt
{
	std::string target;	
	std::string location;
	std::string hash;	
	dcptr_t object;		
	uint64_t size;		
	bool isFileList;	
};

struct ConnectionDataExt
{
	std::string ip;		
	dcptr_t object;		
	uint16_t port;		
	ProtocolType protocol;
	bool isOp;			
	bool isSecure;		
};

struct CommandDataExt
{
	std::string command;
	std::string parameters;
};

struct UDPDataExt
{
	std::string ip;
	uint16_t port;
};

struct TagDataExt
{
	dcptr_t object;
	bool isManaged;
};