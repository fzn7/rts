import json


class IDLUtil:
    def __init__(self):
        pass

    api_config = None

    @classmethod
    def get_api_config(cls):
        if cls.api_config is None:
            api_file = open("Api.json", 'r')
            cls.api_config = json.load(api_file)

        return cls.api_config
