#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <stdlib.h>

int main(int argc, char **argv)
{
	ros::init(argc,argv,"moves");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist> ("/mobile_base/commands/velocity", 1000);
	//Ŭ���� ��ü�� �����Ͽ� ������ �޼����� �����Ų��.

	geometry_msgs::Twist msg; 
	ros::Rate rate(5);  // 5Hz
	int time =0;  //time ���� �ʱ�ȭ
 	

	while(1)	// S��
	{
		msg.linear.x = 0.25;  //���������� 0.25�ӷ��� ���Ѵ�
		msg.angular.z = 0.25;  //��ȸ���� �ϵ����ϰ� 0.25�ӷ��� ���Ѵ�
		pub.publish(msg);	//�޼��� ����	

		time++;                   //time�̶� ������ ���� ī��Ʈ�Ǿ� �ǽð����� �ð��� üũ�Ѵ�.
		if(time==75){break;}  //time�� 75�� �Ǹ� while���� ����������.

		rate.sleep(); //����
	}

	while(1)
	{
		msg.linear.x = 0.25;  //���������� 0.25�ӷ��� ���Ѵ�
		msg.angular.z = -0.25;  //��ȸ���� �ϵ����ϰ� 0.25�ӷ��� ���Ѵ�
		pub.publish(msg);	 //�޼��� ����	

		time++;                    //time�̶� ������ ���� ī��Ʈ�Ǿ� �ǽð����� �ð��� üũ�Ѵ�.
		if(time==162){break;}  //time�� 162�� �Ǹ� while���� ����������.

		rate.sleep(); //����
	}

	
}

	

