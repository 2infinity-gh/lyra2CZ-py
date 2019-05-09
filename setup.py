from setuptools import setup, Extension

lyra2z_hash_module = Extension('lyra2zc_hash',
                               sources = [
										  'lyra2zmodule.c',
                                          'lyra2z.c',
										  'Sponge.c',
										  'Lyra2.c',
										  'blake.c'],
                               include_dirs=['.'])

setup (name = 'lyra2zc_hash',
       version = '0.1.0',
       author_email = 'devwarrior.zcoin@gmail.com',
       author = 'devwarrior',
       url = 'https://github.com/2infinity-gh/lyra2zc-py',
       description = 'Bindings for Lyra2CZ proof of work used by BitcoinCZ',
       ext_modules = [lyra2z_hash_module])

