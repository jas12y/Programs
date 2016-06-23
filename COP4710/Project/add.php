<?php

	if(!empty($_POST['checkbox']))
	{
		foreach($_POST['checkbox'] as $file)
		{
			$FullFileName = realpath($DirectoryToScan.'/'.$file);
			if ((substr($FullFileName, 0, 1) != '.') && is_file($FullFileName))
			{
				$ThisFileInfo = $getID3->analyze($FullFileName);
				getid3_lib::CopyTagsToComments($ThisFileInfo);
				$title = htmlentities(!empty($ThisFileInfo['comments_html']['title'])  ? implode(' ', $ThisFileInfo['comments_html']['title']): chr(160));
				$artist = htmlentities(!empty($ThisFileInfo['comments_html']['artist'])  ? implode(' ', $ThisFileInfo['comments_html']['artist']): chr(160));
				$album = htmlentities(!empty($ThisFileInfo['comments_html']['album'])  ? implode(' ', $ThisFileInfo['comments_html']['album']): chr(160));
				$genre = htmlentities(!empty($ThisFileInfo['comments_html']['genre'])  ? implode(' ', $ThisFileInfo['comments_html']['genre']): chr(160));
				$track = htmlentities(!empty($ThisFileInfo['comments_html']['track'])  ? implode(' ', $ThisFileInfo['comments_html']['track']): chr(160));
				$playtime = htmlentities(!empty($ThisFileInfo['playtime_string']) ? $ThisFileInfo['playtime_string'] : chr(160));

				if($title == "")
				{
					$title = $file;
					$rtitle = html_entity_decode($file);
				}
				else
					$rtitle = html_entity_decode($mysqli->real_escape_string($title));

				$rartist = html_entity_decode($mysqli->real_escape_string($artist));
				$ralbum = html_entity_decode($mysqli->real_escape_string($album));
				$rgenre = html_entity_decode($mysqli->real_escape_string($genre));
				$rfile = html_entity_decode($mysqli->real_escape_string($file));

				$sresult=mysqli_query($con,"SELECT *FROM song WHERE title='$title' || filename='$rfile'");
				$scount=mysqli_num_rows($sresult);
				if($scount==0)
				{
					$result1=mysqli_query($con,"INSERT INTO song values('','$rtitle','$rartist','$rgenre','$playtime','$rfile')");
					if($result1)
						echo '<center>'.$rtitle.' added successfully'.'</center>';

					if($ralbum != "")
					{
						$aresult=mysqli_query($con,"SELECT *FROM album WHERE title='$ralbum' AND artist='$rartist'");
						$acount=mysqli_num_rows($aresult);

						if($acount==0)
						{
							$result2=mysqli_query($con,"INSERT INTO album values('','$ralbum','$rartist','$rgenre')");
							if($result2)
								echo '<center>'.$ralbum.' added successfully'.'</center>';
							$result3=mysqli_query($con,"INSERT INTO ison (songid,albumid,track)
											SELECT s.songid,a.albumid,'$track'
											FROM song s,album a
											WHERE s.title='$rtitle' AND (a.title='$ralbum' AND a.artist='$rartist')");
							if($result3)
								echo '<center>'.'Ison added successfully'.'</center>';
						}
						else
						{
							$arow=mysqli_fetch_array($aresult);
							$aid=$arow['albumid'];
							$result3=mysqli_query($con,"INSERT INTO ison (songid,albumid,track)
											SELECT s.songid,'$aid','$track'
											FROM song s
											WHERE s.title='$rtitle'");
							if($result3)
								echo '<center>'.'Ison added successfully'.'</center>';
						}
					}
				}
				else
					echo '<center>'.$file.' already exists!'.'</center>';
			}
		}
	}
?>