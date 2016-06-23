<html>
<body bgcolor="#808080">
<form action="<?php echo $caller; ?>" method="post">
<div align="center">

<table>
<tr>
<td align="center">Title</td>
<td align="center">Artist</td>
<td align="center">Album</td>
<td align="center">Genre</td>
<td align="center">Playtime</td>
<td align="center">File Name</td>
</tr>

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
			}
?>

<tr bgcolor='<?php if(($color%2)==0) echo "#688e23"; else echo "#d3d3d3"; ?>'>

<td><input name="title" type="text" id="title" required value="<?php echo $title; ?>"></td>
<td><input name="artist" type="text" id="artist" value="<?php echo $artist; ?>"></td>
<td><input name="album" type="text" id="album" value="<?php echo $album; ?>"></td>
<td>
<select name="genre" value="<?php echo $genre;?>">

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
<td><?php echo $playtime; ?></td>
<td><?php echo $file; ?><input name="file[]" type="hidden" value="<?php echo $file; ?>"></td>

<?php
			$color=$color+1;
		}
	}
?>
<input type="submit" name="update" value="Update">
</div>
</form>
</body>
</html>