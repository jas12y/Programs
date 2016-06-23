<form action="<?php echo $caller; ?>" method="post">
<input type="submit" name="update" value="Update">
<div align="center">

<table>
<tr>
<td>&nbsp;</td>
<td align="center">Title</td>
<td align="center">Artist</td>
<td align="center">Album</td>
<td align="center">Genre</td>
<td align="center">Track</td>
<td align="center">Playtime</td>
<td align="center">File Name</td>
</tr>

<?php
	unset($_POST['submit']);
	$_POST['submit']="";
	$dircheck=false;
	if(!empty($_POST['checkbox']))
	{
		foreach($_POST['checkbox'] as $file)
		{
			$FullFileName = realpath($DirectoryToScan.'/'.$file);
			if ((substr($FullFileName, 0, 1) != '.') && is_file($FullFileName))
			{
				$ThisFileInfo = $getID3->analyze($FullFileName);
				getid3_lib::CopyTagsToComments($ThisFileInfo);
				$ftitle = htmlentities(!empty($ThisFileInfo['comments_html']['title'])  ? implode(' ', $ThisFileInfo['comments_html']['title']): chr(160));
				$fartist = htmlentities(!empty($ThisFileInfo['comments_html']['artist'])  ? implode(' ', $ThisFileInfo['comments_html']['artist']): chr(160));
				$falbum = htmlentities(!empty($ThisFileInfo['comments_html']['album'])  ? implode(' ', $ThisFileInfo['comments_html']['album']): chr(160));
				$fgenre = htmlentities(!empty($ThisFileInfo['comments_html']['genre'])  ? implode(' ', $ThisFileInfo['comments_html']['genre']): chr(160));
				$track = htmlentities(!empty($ThisFileInfo['comments_html']['track'])  ? implode(' ', $ThisFileInfo['comments_html']['track']): chr(160));
				$playtime = htmlentities(!empty($ThisFileInfo['playtime_string']) ? $ThisFileInfo['playtime_string'] : chr(160));
			}
			$title = html_entity_decode($ftitle);
			$artist = html_entity_decode($fartist);
			$album = html_entity_decode($falbum);
			$genre = html_entity_decode($fgenre);
?>

<tr bgcolor='<?php if(($color%2)==0) echo "#688e23"; else echo "#d3d3d3"; ?>'>
<td><a href="player.php?pfile=<?php echo urlencode($file);?>" target="player"><img src="button_play_green.png" alt="Play" width="24" height="24"></a></td>
<td><input name="titles[]" type="text" id="titles" required value="<?php echo $title; ?>"></td>
<td><input name="artists[]" type="text" id="artists" value="<?php echo $artist; ?>"></td>
<td><input name="albums[]" type="text" id="albums" value="<?php echo $album; ?>"></td>
<td>
<select name="genres[]" value="<?php echo $genre;?>">

<?php
	foreach($options as $id)
	{
?>

<option value="<?php echo $id;?>" <?php if($genre == $id) echo "SELECTED"; ?> ><?php echo $id;?></option>

<?php
	}
?>

</select>
</td>
<td><input name="tracks[]" type="text" id="tracks" value="<?php echo $track; ?>"></td>
<td><?php echo $playtime; ?></td>
<td><?php echo $file; ?><input name="file[]" type="hidden" value="<?php echo $file; ?>"></td>

<?php
			$color=$color+1;
		}
	}
?>

</div>
</form>