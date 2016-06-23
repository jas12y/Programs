<?php
	$host="localhost";
	$user="root";
	$password="";
	$dbName="hw3";
	
	$con=mysqli_connect($host,$user,$password,$dbName);
	
	if(!$con)
		echo "Could not connect to database";
?>