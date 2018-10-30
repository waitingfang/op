// 找出m~n之间的水仙数。
```
function shuixian(m,n){	
	for(var i=m;i<=n;i++){
		var sum=0;
		var arr=i.toString().split("");
			for(var j=0;j<arr.length;j++){
				var num=parseFloat(arr[j]);
				var z=Math.pow(num,3);
				sum+=z;
			}
			if(i==sum){
				console.log(i);
			}else{
				console.log("null");
			}
	}
};
shuixian(153,154);
```
