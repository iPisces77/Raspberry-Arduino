car.Init=function(){
	$(".button_ctl").each(function(){
		$(this).click(function(){
			data={
				id : $(this)[0].id
			};
			console.log(data);

			car.Common.ajaxRequest("/ctl",data,function(){
				console.log("success");
			});
		});
	});
};
