<?php
	if(isset($_POST['main']))
		header("location:main.php");

	include 'database_connector.php';
	
	if(isset($_POST['submit']))
	{
		$name=$_POST['name'];
		$manuf=$_POST['manuf'];

		$result=mysqli_query($con,"insert into beers values ('','$name','$manuf')");
		if($result)
		{
		echo '<center>'.'Values added successfully'.'</center>';
		}
		else
			echo "no go";

	}
?>

<html>
<body bgcolor="#808080">
<form action="beer.php" method="post">
  <div align="center">
  <table width="200" border="0">
    <tr>
      <td>Name</td>
      <td>&nbsp;</td>
      <td><div align="center">
        <input type="text" name="name" required>
      </div></td>
    </tr>
    <tr>
      <td>Manufacturer</td>
      <td>&nbsp;</td>
      <td><div align="center">
        <input type="text" name="manuf">
      </div></td>
    </tr>
  </table>
    
  <input type="submit" name="submit" value="Add">
    
  </div>
</form>


<form method="post" action="main.php"><input type="submit" name="main" value="Back"></form>
</body>
</html>