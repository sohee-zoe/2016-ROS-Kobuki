#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <iomanip>

#define a time*0.8  //매크로 변수를 통해 a 자체가 time*0.8에 해당하는 값이 된다
#define MAX 1.56  //매크로 변수를 통해 MAX 자체가 1.56이란 값이 된다.

int main(int argc, char **argv)
{
	ros::init(argc,argv,"track");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1000);  
	//클래스 객체를 생성하여 실제로 메세지를 발행시킨다.
	

	geometry_msgs::Twist msg;
	ros::Rate rate(5);  // 5Hz

	int time=0; //time 변수 초기화

//////////////////////////// 1 ////////////////////////////////////////

	while(1)
	{
		msg.linear.x = 0.2*a;    //정방향으로 0.2*a속력을 가한다(가속)
		msg.angular.z = 0.6;    //좌회전을 하도록하고 0.6속력을 가한다

		if(msg.linear.x>=MAX) msg.linear.x=MAX;
		pub.publish(msg);	 //메세지 발행	

			
		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);
		//콘솔창에 time , 속도 , 각도 값을 각각 띄운다.

		time++;      //time이란 변수를 통해 카운트되어 실시간으로 시간을 체크한다.

		if(time==25) break;  //time이 25가 되면 while문을 빠져나간다.
				
		rate.sleep();  //지연
	}


	while(1)
	{
		msg.linear.x = 0.8; 		 //정방향으로 0.8속력을 가한다
		msg.angular.z = 2.05;     //좌회전을 하도록하고 2.05속력을 가한다

		pub.publish(msg);	 //메세지 발행	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==50) break;
		rate.sleep();
	}

//////////////////////////// 2 ////////////////////////////////////////

	while(1)
	{
		msg.linear.x = 1.56;	    //정방향으로 1.56속력을 가한다
		msg.angular.z = 0.3;     //좌회전을 하도록하고 0.3속력을 가한다

		pub.publish(msg);		//메세지 발행	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);
                   
		time++;
		if(time==75) break;
				
		
		rate.sleep();
	}

	while(1)
	{
		msg.linear.x = 0.8; 		 //정방향으로 0.8속력을 가한다
		msg.angular.z = 1.85;    //좌회전을 하도록하고 1.85속력을 가한다

		pub.publish(msg);	  //메세지 발행	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==89) break;
		rate.sleep();
	}
	
//////////////////////////// 3 ////////////////////////////////////////

	while(1)
	{
		msg.linear.x = 1.56;	      //정방향으로 1.56속력을 가한다
		msg.angular.z = 0.0; 
		pub.publish(msg);		//메세지 발행	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==115) break;
				
		
		rate.sleep();
	}

	while(1)
	{
		msg.linear.x = 0.8; 		 //정방향으로 0.8속력을 가한다
		msg.angular.z = 1.8;     	//좌회전을 하도록하고 1.8속력을 가한다

		pub.publish(msg);	        //메세지 발행	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==132) break;
		rate.sleep();
	}

//////////////////////////// 4 ////////////////////////////////////////

	while(1)
	{
		msg.linear.x = 1.56;	      //정방향으로 1.56속력을 가한다
		msg.angular.z = 0.0; 
		pub.publish(msg);		 //메세지 발행	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==152) break;
				
		
		rate.sleep();
	}

	while(1)
	{
		msg.linear.x = 0.8; 		 //정방향으로 0.8속력을 가한다
		msg.angular.z = 2.2; 	//좌회전을 하도록하고 2.2속력을 가한다

		pub.publish(msg);	      //메세지 발행	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);


		time++;
		if(time==180) break;
		rate.sleep();
	}


//////////////////////////// 5 ////////////////////////////////////////

	while(1)
	{
		msg.linear.x = 1.56;	        //정방향으로 1.56속력을 가한다
		msg.angular.z = 0.1; 
		pub.publish(msg);		 //메세지 발행	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==190) break;
				
		
		rate.sleep();
	}
}

	

