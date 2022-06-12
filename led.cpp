#include <ros/ros.h>
#include <geometry_msgs/Twist.h>	// 선속도와 각속도 제어하는 헤더 파일  추가
#include <kobuki_msgs/Sound.h>	// 소리 내기 위한 헤더 파일 추가
#include <kobuki_msgs/Led.h> // LED 켜기 위한 헤더 파일 추가


int main(int argc, char **argv)	
{
  ros::init(argc, argv, "Sound_and_Led"); // ROS systemp 초기화
  ros::NodeHandle nh;	// Establish this program as a ROS node

  // publisher object 생성
  ros::Publisher pub_sound = nh.advertise<kobuki_msgs::Sound>("/mobile_base/commands/sound",10);
  // 퍼블리서 pub_sound 작성 : 토픽명 "/mobile_base/commands/sound", 큐 크기 10
  ros::Publisher pub_led1 = nh.advertise<kobuki_msgs::Led>("/mobile_base/commands/led1",10);
  ros::Publisher pub_led2 = nh.advertise<kobuki_msgs::Led>("/mobile_base/commands/led2",10);
  // 퍼블리서 pub_led 작성 : 토픽명 "/mobile_base/commands/led1, 2", 큐 크기 10
  
  srand(time(0));

  ros::Rate rate(2);	// 발행 빈도 제어 2Hz

  for(int i=0 ; i<3 ; i++)	// SOUND 3번 반복
  {	
    kobuki_msgs::Sound msg;	// sound 메시지를 거북이 메시지로 받는다
    msg.value = 2;	// sound select
    rate.sleep();	// 대기
    pub_sound.publish(msg); // 메시지 발행
    ROS_INFO_STREAM("Beep Sound");	// Sound 울렸다는 INFO 메시지 출력
    rate.sleep();
  }

  rate.sleep();
  

  for(int j=0 ; j<5 ; j++)	// 2개의 LED가 5번 좌우로 번갈아 가며 깜빡거리기
  {
    kobuki_msgs::Led msg;	// LED 메시지를 거북이 메시지로 받는다
    ROS_INFO_STREAM("LED ON/OFF");	// LED가 깜빡거렸음을 INFO 메시지 출력
		
    msg.value = 1;	// 초록색
    pub_led1.publish(msg);	// led1 초록색 출력
    msg.value = 0;	// 꺼짐
    pub_led2.publish(msg);	// led2 꺼짐
    rate.sleep();	// 대기

    msg.value = 0;	// 꺼짐
    pub_led1.publish(msg);	// led1 꺼짐
    msg.value = 3;	// 빨간색
    pub_led2.publish(msg); // led2 빨간색 출력
    rate.sleep();	// 대기
  }

  // led1, 2 모두 꺼짐
  kobuki_msgs::Led msg;
  msg.value = 0;
  pub_led1.publish(msg);
  msg.value = 0;
  pub_led2.publish(msg);
  rate.sleep();


}
