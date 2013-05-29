@file	/etc/apache2/httpd.conf
<table>
	<tr>
		<td>table</td>
		<td>table</td>
		<td>table</td>
	<tr>
	<tr>
		<td>table</td>
		<td>table</td>
		<td>table</td>
	<tr>
	<tr>
		<td>table</td>
		<td>table</td>
		<td>table</td>
	<tr>
</table>
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
