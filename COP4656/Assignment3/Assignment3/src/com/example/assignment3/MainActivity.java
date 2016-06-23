package com.example.assignment3;

import java.util.Random;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
//import android.widget.Toast;

public class MainActivity extends ActionBarActivity
{

	Random rand = new Random();
	
	int cscore = 0,pscore = 0;
	TextView results, compPick, cwins, pwins;
	RadioGroup picks;
	Button button;

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		if (savedInstanceState == null)
		{
			getSupportFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}

		final MediaPlayer loseSound = MediaPlayer.create(MainActivity.this, R.raw.loserhorns);
		final MediaPlayer winSound = MediaPlayer.create(MainActivity.this, R.raw.cheer);
		final MediaPlayer playSound = MediaPlayer.create(MainActivity.this, R.raw.playgame);
		final MediaPlayer loseSpear = MediaPlayer.create(MainActivity.this, R.raw.gameover);
		final MediaPlayer drawSound = MediaPlayer.create(MainActivity.this, R.raw.smbjump);
		button = (Button) findViewById(R.id.button1);
		results = (TextView) findViewById(R.id.textView1);
		compPick = (TextView) findViewById(R.id.textView2);
		pwins = (TextView) findViewById(R.id.textView4);
		cwins = (TextView) findViewById(R.id.textView5);
		picks = (RadioGroup) findViewById(R.id.radioGroup1);
		playSound.start();


		button.setOnClickListener(new View.OnClickListener()
		{

			@Override
			public void onClick(View v)
			{
				int comp = rand.nextInt(3) + 1;
				int selected = picks.getCheckedRadioButtonId();
				RadioButton playerpick = (RadioButton) findViewById(selected);
				String choice = playerpick.getText().toString();

				switch(choice)
				{
			    	case "Rock":
			    		if(comp == 1)
			    		{
			    			compPick.setText(R.string.crock);
			    			results.setText(R.string.draw);
			    			drawSound.start();
			    		}
			    		else if(comp == 2)
			    		{
			    			compPick.setText(R.string.cpaper);
			    			results.setText(R.string.lose);
			    			++cscore;
			    			cwins.setText(""+cscore);
			    			loseSound.start();
			    		}
			    		else
			    		{
			    			compPick.setText(R.string.cspear);
			    			results.setText(R.string.win);
			    			++pscore;
			    			pwins.setText(""+pscore);
			    			winSound.start();
			    		}
			    		break;
			    	case "Paper":
			    		if(comp == 1)
			    		{
			    			compPick.setText(R.string.crock);
			    			results.setText(R.string.win);
			    			++pscore;
			    			pwins.setText(""+pscore);
			    			winSound.start();
			    		}
			    		else if(comp == 2)
			    		{
			    			compPick.setText(R.string.cpaper);
			    			results.setText(R.string.draw);
			    			drawSound.start();
			    		}
			    		else
			    		{
			    			compPick.setText(R.string.cspear);
			    			results.setText(R.string.lose);
			    			++cscore;
			    			cwins.setText(""+cscore);
			    			loseSound.start();
			    		}
			    		break;
			    	case "Spear":
			    		if(comp == 1)
			    		{
			    			compPick.setText(R.string.crock);
			    			results.setText(R.string.lose);
			    			++cscore;
			    			cwins.setText(""+cscore);
			    			loseSpear.start();
			    		}
			    		else if(comp == 2)
			    		{
			    			compPick.setText(R.string.cpaper);
			    			results.setText(R.string.win);
			    			++pscore;
			    			pwins.setText(""+pscore);
			    			winSound.start();
			    		}
			    		else
			    		{
			    			compPick.setText(R.string.cspear);
			    			results.setText(R.string.draw);
			    			drawSound.start();
			    		}
			    		break;
			    	default:
				    		
				}
			}
		});
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	/**
	 * A placeholder fragment containing a simple view.
	 */
	public static class PlaceholderFragment extends Fragment {

		public PlaceholderFragment() {
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_main, container,
					false);
			return rootView;
		}
	}

}
