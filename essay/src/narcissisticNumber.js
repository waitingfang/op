// 找出m~n之间的水仙花数。
function narcissisticNumber(m, n){
		for (var i = m;i <= n;i++) {
				let sum = 0;
				let arr = i.toString().split("");
				for (var j = 0;j < arr.length;j++) {
						// console.log(arr[j]);
						var num = parseFloat(arr[j]);
						var z = Math.pow(num,3);
						sum += z;
				}
				if (i === sum) {
						console.log(i);
				} else {
						console.log("null");
				}
		}
}
narcissisticNumber(1, 154);
