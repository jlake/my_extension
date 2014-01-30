my_extension
=======

An template for making simple php extension.

Install required things
```
$ yum install gcc php php-devel
```

Building the extension
```
$ phpize
$ ./configure
$ make install
```

Add to php.ini
```
extension=my_extension.so
```
