<?php
	unset($_POST['submit']);

	if(!empty($_POST['dcheckbox']))
	{
		foreach($_POST['dcheckbox'] as $file)
		{
			$rfile = $mysqli->real_escape_string($file);

			$dresult=mysqli_query($con,"DELETE FROM song WHERE filename='$rfile'");
			if($dresult)
				echo '<center>'.$file.' deleted from database.'.'</center>';

			$aresult=mysqli_query($con,"SELECT albumid
							FROM album
							WHERE albumid NOT IN (SELECT albumid
										FROM ison)");
			if($aresult)
			{
				while($row=mysqli_fetch_array($aresult))
        			{
					$aid=$row['albumid'];
					$result=mysqli_query($con,"DELETE FROM album WHERE albumid='$aid'");
					if($result)
						echo '<center>'.'Album deleted from database.'.'</center>';
				}
			}
		}
	}
?>