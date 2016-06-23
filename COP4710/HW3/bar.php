<?php
	if(isset($_POST['main']))
		header("location:main.php");

	include 'database_connector.php';
	
	if(isset($_POST['name']))
	{
		$name=$_POST['name'];
		$address=$_POST['address'];
		
		$result=mysqli_query($con,"insert into bars values('','$name','$address')");
		if($result)
		{
		echo '<center>'.'Values added successfully'.'</center>';
		}

	}
?>

<html>
<body bgcolor="#808080">
<form action="bar.php" method="post">
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
      <td>Address</td>
      <td>&nbsp;</td>
      <td><div align="center">
        <input type="text" name="address">
      </div></td>
    </tr>
  </table>
    
  <input type="submit" name="submit" value="Add">
    
  </div>
</form>


<form method="post" action="main.php"><input type="submit" name="main" value="Back"></form>
</body>
</html>