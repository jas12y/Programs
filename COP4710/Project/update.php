<?php
	$TextEncoding = 'UTF-8';
	$i=0;
	if(!empty($_POST['file']))
	{
//		$titles=$_POST['titles'];
//		$artists=$_POST['artists'];
//		$albums=$_POST['albums'];
//		$genres=$_POST['genres'];
//		$tracks=$_POST['tracks'];

		foreach($_POST['file'] as $filename)
		{
			$file=$filename;
			$titles=$_POST['titles'];
			$artists=$_POST['artists'];
			$albums=$_POST['albums'];
			$genres=$_POST['genres'];
			$tracks=$_POST['tracks'];
			$FullFileName = realpath($DirectoryToScan.'/'.$file);
			$ThisFileInfo = $getID3->analyze($FullFileName);
			getid3_lib::CopyTagsToComments($ThisFileInfo);
			$title = htmlentities(!empty($ThisFileInfo['comments_html']['title'])  ? implode(' ', $ThisFileInfo['comments_html']['title']): chr(160));
			$ftitle = html_entity_decode($title);

			$getID3->setOption(array('encoding'=>$TextEncoding));

			require_once('../testread3/getID3-1.9.7/getid3/write.php');
			// Initialize getID3 tag-writing module
			$tagwriter = new getid3_writetags;

			if ((substr($FullFileName, 0, 1) != '.') && is_file($FullFileName))
			{
				//$tagwriter->filename = '/path/to/file.mp3';
				$tagwriter->filename = $FullFileName;
			}
			//$tagwriter->tagformats = array('id3v1', 'id3v2.3');
			$tagwriter->tagformats = array('id3v2.3');

			$tagwriter->overwrite_tags = true;
			//$tagwriter->overwrite_tags = false;
			//$tagwriter->tag_encoding = $TextEncoding;
			$tagwriter->remove_other_tags = true;

			$TagData = array(
				'title'         => array($titles[$i]),
				'artist'        => array($artists[$i]),
				'album'         => array($albums[$i]),
				'genre'         => array($genres[$i]),
				'track'		=> array($tracks[$i])
				);

			$tagwriter->tag_data = $TagData;

			// write tags
			if($tagwriter->WriteTags())
			{
    				echo '<center>'.'Successfully updated '.$file.'</center>';

			if($caller=='search.php')
			{
				$rtitle = html_entity_decode($titles[$i]);
				$rartist = html_entity_decode($artists[$i]);
				$ralbum = html_entity_decode($albums[$i]);
				$rgenre = html_entity_decode($genres[$i]);

				$FullFileName = realpath($DirectoryToScan.'/'.$file);
				if ((substr($FullFileName, 0, 1) != '.') && is_file($FullFileName))
				{/*
					$ThisFileInfo = $getID3->analyze($FullFileName);
					getid3_lib::CopyTagsToComments($ThisFileInfo);
					$title = htmlentities(!empty($ThisFileInfo['comments_html']['title'])  ? implode(' ', $ThisFileInfo['comments_html']['title']): chr(160));
					$artist = htmlentities(!empty($ThisFileInfo['comments_html']['artist'])  ? implode(' ', $ThisFileInfo['comments_html']['artist']): chr(160));
					$album = htmlentities(!empty($ThisFileInfo['comments_html']['album'])  ? implode(' ', $ThisFileInfo['comments_html']['album']): chr(160));
					$genre = htmlentities(!empty($ThisFileInfo['comments_html']['genre'])  ? implode(' ', $ThisFileInfo['comments_html']['genre']): chr(160));
					$track = htmlentities(!empty($ThisFileInfo['comments_html']['track'])  ? implode(' ', $ThisFileInfo['comments_html']['track']): chr(160));

					$ftitle = html_entity_decode($title);
					$fartist = html_entity_decode($artist);
					$falbum = html_entity_decode($album);
					$fgenre = html_entity_decode($genre);
					$ftrack = html_entity_decode($track);*/

					$iresult=mysqli_query($con,"SELECT *FROM ison WHERE songid=(SELECT DISTINCT s.songid FROM song s WHERE title='$rtitle' && artist='$rartist')");
					$icount=mysqli_num_rows($iresult);
					if($icount==0)
					{
						$aresult=mysqli_query($con,"SELECT *FROM album WHERE title='$rtitle' AND artist='$rartist'");
						$acount=mysqli_num_rows($aresult);
						if($acount==0 && $ralbum!="")
						{
							$result1=mysqli_query($con,"INSERT INTO album values('','$ralbum','$rartist','$rgenre')");
								if($result1)
									echo '<center>'.$album.' added successfully'.'</center>';
							$result2=mysqli_query($con,"INSERT INTO ison (songid,albumid,track)
													SELECT s.songid,a.albumid,'$tracks[$i]'
													FROM song s,album a
													WHERE s.title='$ftitle' AND (a.title='$ralbum' AND a.artist='$rartist')");
							if($result2)
								echo '<center>'.'Ison added successfully'.'</center>';
						}
						elseif($ralbum!="")
						{
							$result2=mysqli_query($con,"INSERT INTO ison (songid,albumid,track)
													SELECT s.songid,a.albumid,'$track'
													FROM song s,album a
													WHERE s.title='$ftitle' AND (a.title='$ralbum' AND a.artist='$rartist')");
							if($result2)
								echo '<center>'.'Ison added successfully'.'</center>';
						}	
					}
					else
					{
						$irow=mysqli_fetch_array($iresult);
						$iaid=$irow['albumid'];

						$result3=mysqli_query($con,"UPDATE album SET title='$ralbum', artist='$rartist', genre='$rgenre' WHERE albumid='$iaid'");
						if($result3)
							echo '<center>'.$album.' updated successfully'.'</center>';
					}
					$result4=mysqli_query($con,"UPDATE song SET title='$rtitle', artist='$rartist', genre='$rgenre' WHERE filename='$file'");
					if($result4)
						echo '<center>'.$rtitle.' values updated in database.'.'</center>';
			}
			}
				if (!empty($tagwriter->warnings))
				{

					echo 'There were some warnings:<br>'.implode('<br><br>', $tagwriter->warnings);
				}
			}
			else
			{
				echo '<center>'.'Failed to write tags!<br>'.implode('<br><br>', $tagwriter->errors).'</center>';
			}
			

			++$i;
		}
	}
?>