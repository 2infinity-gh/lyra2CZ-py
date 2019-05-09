from setuptools import setup, Extension

lyra2cz_hash_module = Extension('lyra2c_hash',
                               sources = [
										  'lyra2czmodule.c',
                                          'lyra2cz.c',
										  'Sponge.c',
										  'Lyra2.c',
										  'blake.c'],
                               include_dirs=['.'])

setup (name = 'lyra2cz_hash',
       version = '0.1.0',
       author_email = '2infinity.nl@gmail.com',
       author = '2infinity',
       url = 'https://github.com/2infinity-gh/lyra2cz-py',
       description = 'Bindings for Lyra2CZ proof of work used by BitcoinCZ',
       ext_modules = [lyra2cz_hash_module])

