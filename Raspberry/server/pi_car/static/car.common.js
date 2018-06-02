var car;
if (!!car && (typeof car != 'object' || car.name)) throw new Error("namespace already exists!");
car = {};

car.name = 'iPisces77\'s car control project!';
car.author="iPisces77";
car.version="1.0";
(function($) {

	car.Common = {
		ajaxRequest : _ajaxRequest
	};

	function _ajaxRequest(actionUrl, postData, successHandler,
		errorHandler) {
			setTimeout(function() {
				$.ajax({
					cache : false,
				async : true,
				type : "post",
				url : actionUrl,
				data : postData,
				dataType : "json",
				success : successHandler,
				error : errorHandler
				});
			}, 0);
		}

})(jQuery);
