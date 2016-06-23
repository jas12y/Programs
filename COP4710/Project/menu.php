<?php
	session_start();
	
	if(!isset($_SESSION['username']))
	{
		session_destroy();
		header("location:login.php");
	}
	if(isset($_POST['search']))
		header("location:search.php");

	if(isset($_POST['insert']))
		header("location:insert.php");

	if(isset($_POST['logout']))
		header("location:logout.php");

	if($_SESSION['username'] == 'Stubbs')
	{
		if(isset($_POST['users']))
			header("location:users.php");

	}
?>

<html>
<h1>
<center><font size="7">Main Menu</font></center>
</h1>
<body bgcolor="#808080">
<div align="center">
<form method="post" action="search.php"><input type="submit" name="search" value="Search" style="height:25px; width:100px"></form>

<form method="post" action="insert.php"><input type="submit" name="insert" value="Insert" style="height:25px; width:100px"></form>

<!--*****************************************************************************-->
<?php
	if($_SESSION['username'] == 'Stubbs')
	{
		echo '<form method="post" action="users.php"><input type="submit" name="users" value="Users" style="height:25px; width:100px"></form>';
	}	
?>
<!--*****************************************************************************-->

<form method="post" action="logout.php"><input type="submit" name="logout" value="Log Out" style="height:25px; width:100px"></form>
</div>
</body>
</html>