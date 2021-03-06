package com.example.assignment2;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends ActionBarActivity {

	Button button;
	ImageView image;
	Object check = "nole";
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		if (savedInstanceState == null) {
			getSupportFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
		
		button = (Button) findViewById(R.id.Button1);
		image = (ImageView) findViewById(R.id.imageView1);
		
		button.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				if(v.getTag() == null || v.getTag() == check)
				{
					image.setImageResource(R.drawable.koolgator);
					v.setTag("gator");
					button.setText(R.string.nole);
				}
				else
				{
					image.setImageResource(R.drawable.nole);
					v.setTag(check);
					button.setText(R.string.gator);
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
/*	
	public void clickFunc(View v) {
		button = (Button) findViewById(R.id.Button1);
		image = (ImageView) findViewById(R.id.imageView1);

		if(v.getTag() == null || v.getTag() == check)
		{
			image.setImageResource(R.drawable.nole);
//			v.setTag("gator");
			button.setText(R.string.gator);
			test = false;
		}
		else
		{
			image.setImageResource(R.drawable.koolgator);
//			v.setTag(check);
			button.setText(R.string.nole);
			test = true;
		}
	}
*/	
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
