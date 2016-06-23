<?php
	if(isset($_POST['main']))
		header("location:main.php");

	include 'database_connector.php';
	
	if(isset($_POST['submit']))
	{
		$beer=$_POST['beer'];

		$result=mysqli_query($con,"select id from beers where name='$beer'");
		if($result)
		{
			$beercount=mysqli_num_rows($result);
		}
		if($beercount==0)
		{
			echo '<center>'.'Beer not in Database'.'</center>';
		}
		else
		{
			$temp=mysqli_fetch_array($result);
			$beerid=$temp['id'];
			$beerinfo=mysqli_query($con,"select bar,price from sells where beer='$beerid'");
			if($beerinfo)
			{
				$barcount=mysqli_num_rows($beerinfo);
			}
			if($barcount==0)
			{
				echo '<center>'.'No Seller'.'</center>';
			}
			else
			{
			?>
				<center>
				<table>
				<?php
	        		$color=0;
        			$i=0;
	        		while($row=mysqli_fetch_array($beerinfo))
        			{
					$barid=$row['bar'];
					$price=number_format($row['price'], 2, '.', '');
					$barinfo=mysqli_query($con,"select name from bars where id='$barid'");
					if($barinfo)
					{
						$temp=mysqli_fetch_array($barinfo);
						$barname=$temp['name'];
					}
		        	?>
					<tr bgcolor='<?php if(($color%2)==0) echo "#688e23"; else echo "#d3d3d3"; ?>'>
                			<td><?php echo $barname; ?></td>
	                		<td><?php echo '$'.$price; ?></td>
	              		</tr>
				<?php 
					$color=$color+1;
					$i++;
        			}
			}
        		?>
    			</table>
			</center>
		<?php
		}
	}
?>

<html>
<body bgcolor="#808080">
<form action="search.php" method="post">
  <div align="center">
  <table width="200" border="0">
    <tr>
      <td>Beer</td>
      <td>&nbsp;</td>
      <td><div align="center">
        <input type="text" name="beer" required>
      </div></td>
    </tr>
  </table>
    
  <input type="submit" name="submit" value="Search">
    
  </div>
</form>


<form method="post" action="main.php"><input type="submit" name="main" value="Back"></form>
</body>
</html>