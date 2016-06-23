<?php
	if(isset($_POST['search']))
		header("location:search.php");

	if(isset($_POST['beer']))
		header("location:beer.php");

	if(isset($_POST['bar']))
		header("location:bar.php");

	if(isset($_POST['sells']))
		header("location:sells.php");
	
	include 'database_connector.php';

?>

<html>
<h1>
<center><font size="7">Main Menu</font></center>
</h1>
<body bgcolor="#808080">
  <div align="center">

  <form method="post" action="search.php"><input type="submit" name="search" value="Search" style="height:25px; width:100px"></form>
  <table width="300" border="0" align="center">
  <th>
    <font size="4">Add New Entry</font><br><br>
  </th>
  <tr>
    <td><center><form method="post" action="beer.php"><input type="submit" name="beer" value="Beer" style="height:25px; width:100px"></form></td></center>
  </tr>
  <tr>
    <td><center><form method="post" action="bar.php"><input type="submit" name="bar" value="Bar" style="height:25px; width:100px"></form></td></center>
  </tr>
  <tr>
    <td><center><form method="post" action="sells.php"><input type="submit" name="sells" value="Sells" style="height:25px; width:100px"></form></td></center>
  </tr>
  </div>
</body>
</html>