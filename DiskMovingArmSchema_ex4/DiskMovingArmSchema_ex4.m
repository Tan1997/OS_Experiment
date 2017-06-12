% /**
%  * 
%  * @author:		胡文博
%  * @email:		huwenbo@mail.dlut.edu.cn
%  * @dateTime:		2017-06-12 16:00:26
%  * @description: 	
%  */
accessSequence = load ('diskAccessSequence.txt');
startPoint = 53;

[responseVec,movingArmNum] = SCAN(startPoint,accessSequence);

for i = 2:length(responseVec)
    p1 = draw_arrow([responseVec(i-1),i-2 ], [responseVec(i),i-1],0.1,'g');
end
title(['total number of moving arm:',num2str(movingArmNum)])
[responseVec,movingArmNum2] = SSTF(startPoint,accessSequence);
hold on;
for i = 2:length(responseVec)
    p2 = draw_arrow([responseVec(i-1),i-2 ], [responseVec(i),i-1],0.1,'b');
end
title({['total number of moving arm:']; ['SCAN ',num2str(movingArmNum),',       SSTF ',num2str(movingArmNum2)]})
legend([p1,p2],'SCAN','SSTF')
   
    