% /**
%  * 
%  * @author:		胡文博
%  * @email:		huwenbo@mail.dlut.edu.cn
%  * @dateTime:		2017-06-12 16:01:06
%  * @description: 	
%  */
function [responseVec,movingArmNum] = SSTF(startPoint,accessSequence)
    responseVec = zeros(length(accessSequence)+1);
    responseVec(1) = startPoint;
    movingArmNum = 0;
    for i = 2:length(responseVec)
        [step,index] = min(abs(accessSequence-responseVec(i-1)) );
        movingArmNum = movingArmNum + step;
        responseVec(i) = accessSequence(index);
        accessSequence(index) = [];
    end
end
