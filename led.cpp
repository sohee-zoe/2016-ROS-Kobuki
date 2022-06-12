#include <ros/ros.h>
#include <geometry_msgs/Twist.h>	// ���ӵ��� ���ӵ� �����ϴ� ��� ����  �߰�
#include <kobuki_msgs/Sound.h>	// �Ҹ� ���� ���� ��� ���� �߰�
#include <kobuki_msgs/Led.h> // LED �ѱ� ���� ��� ���� �߰�


int main(int argc, char **argv)	
{
  ros::init(argc, argv, "Sound_and_Led"); // ROS systemp �ʱ�ȭ
  ros::NodeHandle nh;	// Establish this program as a ROS node

  // publisher object ����
  ros::Publisher pub_sound = nh.advertise<kobuki_msgs::Sound>("/mobile_base/commands/sound",10);
  // �ۺ��� pub_sound �ۼ� : ���ȸ� "/mobile_base/commands/sound", ť ũ�� 10
  ros::Publisher pub_led1 = nh.advertise<kobuki_msgs::Led>("/mobile_base/commands/led1",10);
  ros::Publisher pub_led2 = nh.advertise<kobuki_msgs::Led>("/mobile_base/commands/led2",10);
  // �ۺ��� pub_led �ۼ� : ���ȸ� "/mobile_base/commands/led1, 2", ť ũ�� 10
  
  srand(time(0));

  ros::Rate rate(2);	// ���� �� ���� 2Hz

  for(int i=0 ; i<3 ; i++)	// SOUND 3�� �ݺ�
  {	
    kobuki_msgs::Sound msg;	// sound �޽����� �ź��� �޽����� �޴´�
    msg.value = 2;	// sound select
    rate.sleep();	// ���
    pub_sound.publish(msg); // �޽��� ����
    ROS_INFO_STREAM("Beep Sound");	// Sound ��ȴٴ� INFO �޽��� ���
    rate.sleep();
  }

  rate.sleep();
  

  for(int j=0 ; j<5 ; j++)	// 2���� LED�� 5�� �¿�� ������ ���� �����Ÿ���
  {
    kobuki_msgs::Led msg;	// LED �޽����� �ź��� �޽����� �޴´�
    ROS_INFO_STREAM("LED ON/OFF");	// LED�� �����ŷ����� INFO �޽��� ���
		
    msg.value = 1;	// �ʷϻ�
    pub_led1.publish(msg);	// led1 �ʷϻ� ���
    msg.value = 0;	// ����
    pub_led2.publish(msg);	// led2 ����
    rate.sleep();	// ���

    msg.value = 0;	// ����
    pub_led1.publish(msg);	// led1 ����
    msg.value = 3;	// ������
    pub_led2.publish(msg); // led2 ������ ���
    rate.sleep();	// ���
  }

  // led1, 2 ��� ����
  kobuki_msgs::Led msg;
  msg.value = 0;
  pub_led1.publish(msg);
  msg.value = 0;
  pub_led2.publish(msg);
  rate.sleep();


}
