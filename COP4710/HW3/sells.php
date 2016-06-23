<?php
	if(isset($_POST['main']))
		header("location:main.php");

	include 'database_connector.php';
	
	if(isset($_POST['submit']))
	{
		$beer=$_POST['beer'];
		$bar=$_POST['bar'];
		$price=$_POST['price'];
		
		$info1=mysqli_query($con,"select id from beers where name='$beer'");
		$temp1=mysqli_fetch_array($info1);
		$info2=mysqli_query($con,"select id from bars where name='$bar'");
		$temp2=mysqli_fetch_array($info2);
		$beerid=$temp1['id'];
		$barid=$temp2['id'];

		$result=mysqli_query($con,"insert into sells values('$beerid','$barid',$price)");
		if($result)
		{
		echo '<center>'.'Values added successfully'.'</center>';
		}
	}
?>

<html>
<body bgcolor="#808080">
<form action="sells.php" method="post">
  <div align="center">
  <table width="200" border="0">
    <tr>
      <td>Beer</td>
      <td>&nbsp;</td>
      <td><div align="center">
        <input type="text" name="beer" required>
      </div></td>
    </tr>
    <tr>
      <td>Bar</td>
      <td>&nbsp;</td>
      <td><div align="center">
        <input type="text" name="bar" required>
      </div></td>
    </tr>
    <tr>
      <td>Price</td>
      <td>&nbsp;</td>
      <td><div align="center">
        <input type="number" step="any" min="0" name="price">
      </div></td>
    </tr>
  </table>
    
  <input type="submit" name="submit" value="Add">
    
  </div>
</form>


<form method="post" action="main.php"><input type="submit" name="main" value="Back"></form>
</body>
</html>