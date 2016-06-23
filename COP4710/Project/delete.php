<center>
<form action="search.php" method="post">
<table cellpadding="3">

<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td align="center">Title</td>
<td align="center">Artist</td>
<td align="center">Album</td>
<td align="center">Genre</td>
<td align="center">Playtime</td>
<td align="center">File Name</td>
</tr>

<?php
	unset($_POST['submit']);

	if(empty($_POST['checkbox']))
		$_POST['checkbox']=$_POST['dfile'];
	if(!empty($_POST['checkbox']))
	{
		foreach($_POST['checkbox'] as $file)
		{
			$rfile = $mysqli->real_escape_string($file);
			$result=mysqli_query($con,"SELECT *FROM song WHERE filename='$rfile'");

			if($result)
			{
		        	while($row=mysqli_fetch_array($result))
        			{
					$songid=$row['songid'];
					$result2=mysqli_query($con,"SELECT DISTINCT a.albumid, a.title album
								FROM album a
								WHERE (SELECT DISTINCT albumid
									FROM ison
									WHERE songid='$songid')=a.albumid
									");
					$row2=mysqli_fetch_array($result2);	
?>

<tr bgcolor='<?php if(($color%2)==0) echo "#688e23"; else echo "#d3d3d3"; ?>'>
<td>
<input type="image" width="24" height="24" src="button_play_green.png" name="dplay" alt="Play" value="<?php echo $row['filename'];?>">
</td>
<td><input type="checkbox" name="dcheckbox[]" id="dcheckbox[]" <?php if($dchecked) echo 'checked'; ?> value="<?php echo $row['filename']; ?>"></form></td>
<td><?php echo $row['title']; ?></td>
<td><?php echo $row['artist']; ?></td>
<td><?php echo $row2['album']; ?></td>
<td><?php echo $row['genre']; ?></td>
<td><?php echo $row['playtime']; ?></td>
<td><?php echo $row['filename']; ?><input name="dfile[]" type="hidden" value="<?php echo $row['filename']; ?>"></td>
</tr>

<?php
					$color=$color+1;
				}
        		}
		}
	}
?>

<?php
	if($dchecked)
	{
?>

<input type="submit" name="dall" value="Select None">

<?php
	}
	else
	{
?>

<input type="submit" name="dall" value="Select All">

<?php
	}
?>

<br/>
<input type="submit" name="dbdelete" value="Delete from Database">
</table>
</form>
</center>