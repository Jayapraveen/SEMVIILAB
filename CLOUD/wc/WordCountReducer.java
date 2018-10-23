import java.io.IOException;
import java.util.Iterator;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.mapred.JobConf;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reducer;
import org.apache.hadoop.mapred.Reporter;
import org.apache.hadoop.io.Text;

public class WordCountReducer implements Reducer<Text,IntWritable,Text,IntWritable> {
 @Override
 
public void configure(JobConf arg0) { 
 
 
// TODO Auto-generated method stub  
 
} 
 @Override
 
public void close() throws IOException { 
 
 
// TODO Auto-generated method stub  
 
} 
 @Override
 
public void reduce(Text arg0, Iterator<IntWritable> arg1, OutputCollector<Text, 
IntWritable> arg2, Reporter arg3)
 
 
 
throws IOException { 
 
 
// TODO Auto-generated method stub 
 
 
int count=0; 
 
 
while(arg1.hasNext()) 
 
 
{ 
 
 
 
IntWritable i=arg1.next(); 
 
 
 
count+=i.get(); 
 
 
} 
 
 
arg2.collect(arg0,new IntWritable(count)); 
 
 
 
 
} 
}
