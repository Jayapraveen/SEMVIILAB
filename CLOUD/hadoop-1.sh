#!/bin/bash

# Function for asking to proceed
confirm () {
  read -r -p "${1:-Are you sure? [y/N]} " response
  case $response in
    [yY][eE][sS]|[yY])
      true
      ;;
     *)
      false
      ;;
  esac
}
function update_apt_repo  {
  sudo add-apt-repository ppa:webupd8team/java
  sudo apt-get update 
} 
function install_java {
  sudo apt-get install oracle-java8-installer
  sudo apt-get install oracle-java8-set-default
}

function create_hadoop_user {

  sudo useradd -m hduser
  sudo adduser hduser sudo
  sudo chsh -s /bin/bash hduser
  sudo passwd hduser
  
}
function install_hadoop {
  sudo mkdir -p /usr/local/hadoop/
  cd /usr/local/hadoop
  sudo curl http://ftp.tc.edu.tw/pub/Apache/hadoop/common/hadoop-2.7.2/hadoop-2.7.2.tar.gz | sudo tar xz 
  sudo chown -R hadoop /usr/local/hadoop
}

function setup_profile {
  local file=/etc/profile.d/hadoop-init.sh
  local tempfile=/tmp/hadoop_setup_sdfds.sh
  sudo mkdir -p /tmp/hadoop
  sudo chown hduser -R /tmp/hadoop
  export HADOOP_HOME=/usr/local/hadoop/hadoop-2.7.2
  export PATH=$PATH:$HADOOP_HOME/bin:$HADOOP_HOME/sbin
  cat >> $tempfile  <<EOT
export HADOOP_HOME=/usr/local/hadoop/hadoop-2.7.2
export PATH=\$PATH:\$HADOOP_HOME/bin:\$HADOOP_HOME/sbin
EOT
  tempfile=/tmp/hadoop_setup_sdfds.sh
  chmod +x $tempfile
  sudo chown root $tempfile
  sudo mv $tempfile $file
}

function setup_core_xml {
  export HADOOP_HOME=/usr/local/hadoop/hadoop-2.7.2
  local tmpfile=/tmp/hadoop_fafsa.xml
  local file=$HADOOP_HOME/etc/hadoop/core-site.xml
  sudo rm -rf $file
  cat >> $tmpfile <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<?xml-stylesheet type="text/xsl" href="configuration.xsl"?>
<configuration>
<property>
    <name>hadoop.tmp.dir</name>
    <value>/tmp/hadooop</value>
    <description>Temporary directories.</description>
</property>

<property>
    <name>fs.default.name</name>
    <value>hdfs://localhost:54310</value>
    <description>A URI whose scheme and authority determine the FileSystem implementation. </description>
</property>
</configuration>

EOF
  tmpfile=/tmp/hadoop_fafsa.xml
  sudo chown root $tmpfile
  sudo mv $tmpfile $file
}

function setup_mapred_xml {
  export HADOOP_HOME=/usr/local/hadoop/hadoop-2.7.2
  local tmpfile=/tmp/hadoop_mapred.xml
  local file=$HADOOP_HOME/etc/hadoop/mapred-site.xml
  sudo rm -rf $file
  cat >> $tmpfile <<EOT
<?xml version="1.0" encoding="UTF-8"?>
<?xml-stylesheet type="text/xsl" href="configuration.xsl"?>
<configuration>
<property>
  <name>mapred.job.tracker</name>
  <value>localhost:54311</value>
  <description>The tracker of MapReduce</description>
</property>
</configuration>

EOT
  tmpfile=/tmp/hadoop_mapred.xml
  sudo chown root $tmpfile
  sudo mv $tmpfile $file
}

function setup_hdfs_xml {
  export HADOOP_HOME=/usr/local/hadoop/hadoop-2.7.2
  local tmpfile=/tmp/hadoop_hdfs.xml
  local file=$HADOOP_HOME/etc/hadoop/hdfs-site.xml
  sudo rm -rf $file
  cat >> $tmpfile <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<?xml-stylesheet type="text/xsl" href="configuration.xsl"?>
<configuration>
<property>
  <name>dfs.replication</name>
  <value>1</value>
  <description>Number of replication of hdfs</description>
</property>
</configuration>

EOF
  tmpfile=/tmp/hadoop_hdfs.xml
  sudo chown root $tmpfile
  sudo mv $tmpfile $file
}


function setup_environment {
  export HADOOP_HOME=/usr/local/hadoop/hadoop-2.7.2
  sudo sed -i -- 's/JAVA_HOME=\${JAVA_HOME}/JAVA_HOME=\$(readlink -f \/usr\/bin\/java | sed "s:bin\/java::")/' $HADOOP_HOME/etc/hadoop/hadoop-env.sh
  setup_profile
  setup_core_xml
  setup_mapred_xml
  setup_hdfs_xml
  sudo chown -R hduser $HADOOP_HOME
}

confirm "Update Repository? [y/N] " && update_apt_repo 
confirm "Install Java? [y/N] " && install_java
confirm "Create hadoop user? [y/N] " && create_hadoop_user
confirm "Install hadoop? [y/N] " && install_hadoop 
confirm "Setup Hadoop Environment" &&  setup_environment

