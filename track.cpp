#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <iomanip>

#define a time*0.8  //��ũ�� ������ ���� a ��ü�� time*0.8�� �ش��ϴ� ���� �ȴ�
#define MAX 1.56  //��ũ�� ������ ���� MAX ��ü�� 1.56�̶� ���� �ȴ�.

int main(int argc, char **argv)
{
	ros::init(argc,argv,"track");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1000);  
	//Ŭ���� ��ü�� �����Ͽ� ������ �޼����� �����Ų��.
	

	geometry_msgs::Twist msg;
	ros::Rate rate(5);  // 5Hz

	int time=0; //time ���� �ʱ�ȭ

//////////////////////////// 1 ////////////////////////////////////////

	while(1)
	{
		msg.linear.x = 0.2*a;    //���������� 0.2*a�ӷ��� ���Ѵ�(����)
		msg.angular.z = 0.6;    //��ȸ���� �ϵ����ϰ� 0.6�ӷ��� ���Ѵ�

		if(msg.linear.x>=MAX) msg.linear.x=MAX;
		pub.publish(msg);	 //�޼��� ����	

			
		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);
		//�ܼ�â�� time , �ӵ� , ���� ���� ���� ����.

		time++;      //time�̶� ������ ���� ī��Ʈ�Ǿ� �ǽð����� �ð��� üũ�Ѵ�.

		if(time==25) break;  //time�� 25�� �Ǹ� while���� ����������.
				
		rate.sleep();  //����
	}


	while(1)
	{
		msg.linear.x = 0.8; 		 //���������� 0.8�ӷ��� ���Ѵ�
		msg.angular.z = 2.05;     //��ȸ���� �ϵ����ϰ� 2.05�ӷ��� ���Ѵ�

		pub.publish(msg);	 //�޼��� ����	

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
		msg.linear.x = 1.56;	    //���������� 1.56�ӷ��� ���Ѵ�
		msg.angular.z = 0.3;     //��ȸ���� �ϵ����ϰ� 0.3�ӷ��� ���Ѵ�

		pub.publish(msg);		//�޼��� ����	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);
                   
		time++;
		if(time==75) break;
				
		
		rate.sleep();
	}

	while(1)
	{
		msg.linear.x = 0.8; 		 //���������� 0.8�ӷ��� ���Ѵ�
		msg.angular.z = 1.85;    //��ȸ���� �ϵ����ϰ� 1.85�ӷ��� ���Ѵ�

		pub.publish(msg);	  //�޼��� ����	

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
		msg.linear.x = 1.56;	      //���������� 1.56�ӷ��� ���Ѵ�
		msg.angular.z = 0.0; 
		pub.publish(msg);		//�޼��� ����	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==115) break;
				
		
		rate.sleep();
	}

	while(1)
	{
		msg.linear.x = 0.8; 		 //���������� 0.8�ӷ��� ���Ѵ�
		msg.angular.z = 1.8;     	//��ȸ���� �ϵ����ϰ� 1.8�ӷ��� ���Ѵ�

		pub.publish(msg);	        //�޼��� ����	

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
		msg.linear.x = 1.56;	      //���������� 1.56�ӷ��� ���Ѵ�
		msg.angular.z = 0.0; 
		pub.publish(msg);		 //�޼��� ����	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==152) break;
				
		
		rate.sleep();
	}

	while(1)
	{
		msg.linear.x = 0.8; 		 //���������� 0.8�ӷ��� ���Ѵ�
		msg.angular.z = 2.2; 	//��ȸ���� �ϵ����ϰ� 2.2�ӷ��� ���Ѵ�

		pub.publish(msg);	      //�޼��� ����	

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
		msg.linear.x = 1.56;	        //���������� 1.56�ӷ��� ���Ѵ�
		msg.angular.z = 0.1; 
		pub.publish(msg);		 //�޼��� ����	

		ROS_INFO_STREAM("time = " << std::setw(3) << time 
			<< ", linear = " << std::setw(3) << msg.linear.x 
			<< ", angular = " << std::setw(3) << msg.angular.z);

		time++;
		if(time==190) break;
				
		
		rate.sleep();
	}
}

	

