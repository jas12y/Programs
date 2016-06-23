<?php
	$host="localhost";
	$user="root";
	$password="";
	$dbName="music";
	
	$con=mysqli_connect($host,$user,$password,$dbName);
	
	if(!$con)
		echo "Could not connect to database";
?>