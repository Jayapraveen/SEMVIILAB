import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.mapred.FileInputFormat;
import org.apache.hadoop.mapred.FileOutputFormat;
import org.apache.hadoop.mapred.JobClient;
import org.apache.hadoop.mapred.JobConf;

import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;
import org.apache.hadoop.io.Text;

public class WordCount extends Configured implements Tool {

 @Override
 
public int run(String[] arg0) throws Exception { 
 
 
// TODO Auto-generated method stub 
 
 
if(arg0.length<2) 
 
 
{ 
 
 
 
System.out.println("check the command line arguments"); 
 
 
} 
 
 
JobConf conf=new JobConf(WordCount.class); 
 
 
FileInputFormat.setInputPaths(conf, new Path(arg0[0])); 
 
 
 
FileOutputFormat.setOutputPath(conf, new Path(arg0[1])); 
 
 
 
conf.setMapperClass(WordMapper.class); 
 
 
 
conf.setReducerClass(WordReducer.class); 
 
 
 
conf.setOutputKeyClass(Text.class); 
 
 
 
conf.setOutputValueClass(IntWritable.class); 
 
 
 
conf.setOutputKeyClass(Text.class); 
 
 
 
conf.setOutputValueClass(IntWritable.class); 
 
 
 
JobClient.runJob(conf); 
 
 
 
 
 
 
 
 
 
 
 
 
 
return 0; 
 
} 
 
public static void main(String args[]) throws Exception 
 
{ 
 
 
int exitcode=ToolRunner.run(new WordCount(), args); 
 
 
System.exit(exitcode); 
 
 
 
 
} 
}
