

class PluginSetting(object):
    def __init__(
        self, name, value, defaultValue, dataType, description, validValues
    ):
        self.name = name
        self.value = value
        self.defaultvalue = defaultValue
        self.datatype = dataType
        self.description = description
        self.validvalues = validValues


class CommandData(object):
    def __init__(self, command, parameters):
        self.command = command
        self.parameters = parameters


class ConnectionData(object):
    def __init__(self, ip, port, protocolType, isOperator, isEncrypted):
        self.ip = ip
        self.port = port
        self.protocolType = protocolType
        self.isOperator = isOperator
        self.isEncrypted = isEncrypted


class HubData(object):
    def __init__(self, url, ip, port, protocolType, isOp, isSecure):
        self.url = url
        self.ip = ip
        self.port = port
        self.protocolType = protocolType
        self.isOp = isOp
        self.isSecure = isSecure


class PluginInformation(object):
    def __init__(
        self, name, description, author, web, version, APIVersion, UUID
    ):
        self.name = name
        self.description = description
        self.author = author
        self.web = web
        self.version = version
        self.apiversion = APIVersion
        self.uuid = UUID
        # self.settings = settings;


class QueueData(object):
    def __init__(self, target, location, hash_, filesize, isfilelist):
        self.target = target
        self.location = location
        self.hash = hash_
        self.fileSize = filesize
        self.isFileList = isfilelist


class StringData(object):
    def __init__(self, input_, output_):
        self.input = input_
        self.output = output_


class TagData(object):
    def __init__(self):
        self.isManaged = True


class UDPData(object):
    def __init__(self, remoteAddress, port):
        self.remoteAddress = remoteAddress
        self.port = port


class UserData(object):
    def __init__(self, nick, hubHint, cid, sid, protocol, isOperator):
        self.nick = nick
        self.hubHint = hubHint
        self.cid = cid
        self.sid = sid
        self.protocol = protocol
        self.isOperator = isOperator
