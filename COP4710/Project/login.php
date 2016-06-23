<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Database Project</title>
</head>
<h1>
<center><font size="7">Login</font></center>
</h1>
<body bgcolor="#808080">
<br><br><br><br><br><br><br><br><br>
<!--*****************************************************************************-->
<?php
$username="";
session_start();
include 'database_connector.php';

if(isset($_POST['submit']))
{
	$username=$_POST['username'];
	$password=$_POST['password'];
	//echo $username.$password;

	$result=mysqli_query($con,"select *from users where userid='$username' and password='$password'");
	if($result)
	{
		$count=mysqli_num_rows($result);	
	}
	if($count==1)
	{
		$_SESSION['username']=$username;
		$_SESSION['password']=$password;
		header("location:menu.php");
	}
	else
	{	
		//header("location:login.php");	
		echo '<center>'."<font color='red'>Incorrect Username and/or Password</font>".'</center>';
	}
}
else
{
	echo '<br>';
}
?>
<!--*****************************************************************************-->
<form name="form1" method="post" action="login.php">
<table width="300" align="center" cellpadding="0" cellspacing="1">
<tr>
  		
  	<td>
		<table width="100%" cellpadding="3" cellspacing="1" bgcolor="#808080">
  			<!--<tr>
  				<td colspan="3"><div align="center"><strong>Login </strong></div></td>
  			</tr>-->
  			<tr>
                  <td width="78">Username</td>
                  <td width="6">:</td>
                  <td width="294"><input name="username" type="text" required id="username" autofocus value="<?php echo $username;?>"></td>
            </tr>
            <tr>
                  <td>Password</td>
                  <td>:</td>
                  <td><input name="password" type="password" required id="password"></td>
            </tr>
            <tr>
                  <td>&nbsp;</td>
                  <td>&nbsp;</td>
                  <td><input type="submit" name="submit" value="submit"></td>
            </tr>
		</table>
	</td>
  		
 </tr>
</table>
</form>
</body>
</html>