@file	/etc/apache2/httpd.conf
```
ServerName localhost:80
#DocumentRoot "/var/www"
DocumentRoot "/home/sqm/web"

<Directory />
	Options FollowSymLinks
	AllowOverride None
	Order deny,allow
	Allow from all
</Directory>

<Directory /home/sqm/web>
	Options FollowSymLinks
	AllowOverride None
	Order deny,allow
	Allow from all
</Directory>

<Directory /home/sqm/tmp/html>
	Options FollowSymLinks
	AllowOverride None
	Order deny,allow
	Allow from all
</Directory>

<VirtualHost *:80>
	DocumentRoot "/home/sqm/web"
	ServerName localhost:80
	Directoryindex index.html index.php index.htm
</VirtualHost>
<VirtualHost *:8080>
	DocumentRoot "/home/sqm/tmp/html"
	ServerName localhost:8080
	Directoryindex index.html index.php index.htm
</VirtualHost>
```
## port.conf
```
# If you just change the port or add more ports here, you will likely also
# have to change the VirtualHost statement in
# /etc/apache2/sites-enabled/000-default
# This is also true if you have upgraded from before 2.2.9-3 (i.e. from
# Debian etch). See /usr/share/doc/apache2.2-common/NEWS.Debian.gz and
# README.Debian.gz

NameVirtualHost *:80
Listen 80

NameVirtualHost *:8000
Listen 8000

<IfModule mod_ssl.c>
    # If you add NameVirtualHost *:443 here, you will also have to change
    # the VirtualHost statement in /etc/apache2/sites-available/default-ssl
    # to <VirtualHost *:443>
    # Server Name Indication for SSL named virtual hosts is currently not
    # supported by MSIE on Windows XP.
    Listen 443
</IfModule>

<IfModule mod_gnutls.c>
    Listen 443
</IfModule>

```
