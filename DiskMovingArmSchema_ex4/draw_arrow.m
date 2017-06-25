% /**
%  * 
%  * @author:		胡文博
%  * @email:		huwenbo@mail.dlut.edu.cn
%  * @dateTime:		2017-06-12 16:01:24
%  * @description: 	绘制带箭头的直线函数
 % */
function out = draw_arrow(startpoint,endpoint,headsize,color)
	% accepts two [x y] coords and one double headsize 
	v1 = headsize*(startpoint-endpoint)/2.5; 
	theta = 22.5*pi/180; 
	theta1 = -1*22.5*pi/180; 
	rotMatrix = [cos(theta)  -sin(theta) ; sin(theta)  cos(theta)];
	rotMatrix1 = [cos(theta1)  -sin(theta1) ; sin(theta1)  cos(theta1)];  
	v2 = v1*rotMatrix; 
	v3 = v1*rotMatrix1; 
	x1 = endpoint;
	x2 = x1 + v2; 
	x3 = x1 + v3; 
	hold on; 
	% fill([x1(1) x2(1) x3(1)],[x1(2) x2(2) x3(2)],[0 0 0]);% this fills the arrowhead (black) 
	str=['(' num2str(x1(1)) ',' num2str(x1(2)) ')'];
	out = plot([startpoint(1) endpoint(1)],[startpoint(2) endpoint(2)],'-o','linewidth',1,'color',color);
	set(gca,'ydir','reverse')
	text(x1(1)+0.2,x1(2)+0.1,str);