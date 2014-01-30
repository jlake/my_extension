PHP_ARG_ENABLE(my_extension, whether to enable my extension,
[ --enable-my-extension   Enable my extension])

if test "$PHP_MY_EXTENSION" = "yes"; then
  AC_DEFINE(HAVE_MY_EXTENSION, 1, [Whether you have my extension])
  PHP_NEW_EXTENSION(my_extension, my_extension.c, $ext_shared)
fi
