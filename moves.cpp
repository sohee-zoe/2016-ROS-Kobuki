#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <stdlib.h>

int main(int argc, char **argv)
{
	ros::init(argc,argv,"moves");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist> ("/mobile_base/commands/velocity", 1000);
	//클래스 객체를 생성하여 실제로 메세지를 발행시킨다.

	geometry_msgs::Twist msg; 
	ros::Rate rate(5);  // 5Hz
	int time =0;  //time 변수 초기화
 	

	while(1)	// S자
	{
		msg.linear.x = 0.25;  //정방향으로 0.25속력을 가한다
		msg.angular.z = 0.25;  //좌회전을 하도록하고 0.25속력을 가한다
		pub.publish(msg);	//메세지 발행	

		time++;                   //time이란 변수를 통해 카운트되어 실시간으로 시간을 체크한다.
		if(time==75){break;}  //time이 75가 되면 while문을 빠져나간다.

		rate.sleep(); //지연
	}

	while(1)
	{
		msg.linear.x = 0.25;  //정방향으로 0.25속력을 가한다
		msg.angular.z = -0.25;  //우회전을 하도록하고 0.25속력을 가한다
		pub.publish(msg);	 //메세지 발행	

		time++;                    //time이란 변수를 통해 카운트되어 실시간으로 시간을 체크한다.
		if(time==162){break;}  //time이 162가 되면 while문을 빠져나간다.

		rate.sleep(); //지연
	}

	
}

	

