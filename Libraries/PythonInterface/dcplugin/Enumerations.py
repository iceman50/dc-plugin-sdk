

def _enum(**enums):
    return type('Enum', (), enums)


def _enum2(*sequential, **named):
    enums = dict(zip(sequential, range(len(sequential))), **named)
    return type('Enum', (), enums)


TagPathType = _enum2(
    'GlobalConfig',
    'UserConfig',
    'UserLocal',
    'Resources',
    'Locale'
)

ProtocolType = _enum2(
    'ADC',
    'NMDC',
    'DHT'
)

MessageType = _enum2(
    'Client',
    'Status',
    'System'
)

QueuePriority = _enum(
    Default=-1,
    Lowest=1,
    Low=2,
    Normal=3,
    High=4,
    Highest=5
)

DataType = _enum2(
    'Unknown',
    'String',
    'Byte',
    'Short',
    'Int',
    'Long'
)
