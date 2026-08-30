#!/usr/bin/env python3
""" User class
"""

import hashlib
import uuid


class User:
    """ User class
    """

    def __init__(self):
        """ Initialize a new user
        """
        self.id = str(uuid.uuid4())
        self.password = None

    @property
    def password(self):
        """ password getter """
        return self.__password

    @password.setter
    def password(self, pwd):
        """ password setter """
        if pwd is None:
            self.__password = None
        else:
            self.__password = hashlib.md5(pwd.encode()).hexdigest()

    def is_valid_password(self, pwd):
        """ Validate password """
        if pwd is None or self.__password is None:
            return False
        return self.__password == hashlib.md5(pwd.encode()).hexdigest()
