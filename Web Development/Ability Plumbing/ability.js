$(document).ready(function(){
    const reviewButton = $(".leave-a-review input");

    $(".button-p button").click(function () { 
        window.location.href='tel:765-999-9999';
    });

    $(".appointment-buttons button:nth-of-type(1)").click(function () { 
        window.location.href='tel:765-999-9999';
    });

    $(".appointment-buttons button:nth-of-type(2)").click(function () { 
        window.location.href='tel:765-111-1111';
    });

    $(reviewButton).click(function(){
        alert("Your review has been submitted. We appreciate your feedback!");
    });

    $("form").submit(function(){
        alert("Appointment scheduled.");
    });

    $(".quick-links").mouseover(function () { 
        $(".quick-links").css("opacity", "1");
    });

    if(window.matchMedia('(min-width: 1365px)').matches){
        $(".quick-links a:nth-of-type(1)").click(function(){
            $(".service-list img:nth-of-type(1)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(2)").fadeIn().stop(true, true);
            $(window).scrollTop(790);
            $(".service-list img:nth-of-type(1)").hide();
            $(".service-list img:nth-of-type(1)").fadeIn();
        });
        $(".quick-links a:nth-of-type(2)").click(function(){
            $(".service-list img:nth-of-type(2)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(1)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(3)").fadeIn().stop(true, true);
            $(window).scrollTop(1254);
            $(".service-list img:nth-of-type(2)").hide();
            $(".service-list img:nth-of-type(2)").fadeIn(1000);
        });
        $(".quick-links a:nth-of-type(3)").click(function(){
            $(".service-list img:nth-of-type(1)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(2)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(3)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(4)").fadeIn().stop(true, true);
            $(window).scrollTop(1729);
            $(".service-list img:nth-of-type(3)").hide();
            $(".service-list img:nth-of-type(3)").fadeIn(1000);
        });
        $(".quick-links a:nth-of-type(4)").click(function(){
            $(".service-list img:nth-of-type(1)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(2)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(3)").fadeIn().stop(true, true);
            $(".service-list img:nth-of-type(4)").fadeIn().stop(true, true);
            $(window).scrollTop(2043);
            $(".service-list img:nth-of-type(4)").hide();
            $(".service-list img:nth-of-type(4)").fadeIn(1000);
        });

        $(window).scroll(function(){
            if($(window).scrollTop() <= 137){
                $(".service-list img:nth-of-type(1)").fadeOut();
            }
            if($(window).scrollTop() >= 154){
                $(".service-list img:nth-of-type(1)").fadeIn(1000);
            }
            if($(window).scrollTop() <= 608){
                $(".service-list img:nth-of-type(2)").fadeOut();
            }
            if($(window).scrollTop() >= 630){
                $(".service-list img:nth-of-type(2)").fadeIn(1000);
            }
            if($(window).scrollTop() <= 1076){
                $(".service-list img:nth-of-type(3)").fadeOut();
            }
            if($(window).scrollTop() >= 1105){
                $(".service-list img:nth-of-type(3)").fadeIn(1000);
            }
            if($(window).scrollTop() <= 1549){
                $(".service-list img:nth-of-type(4)").fadeOut();
            }
            if($(window).scrollTop() >= 1582){
                $(".service-list img:nth-of-type(4)").fadeIn(1000);
            }
        });
    }
    if(window.matchMedia('(max-width: 1023px)').matches){
        $(".quick-links").css("display", "none");
    }

    if(window.matchMedia('(max-width: 1364px)').matches){

        $(".service-list h2:nth-of-type(1)").attr("id", "appliances");
        $(".service-list h2:nth-of-type(2)").attr("id", "clogged-drains");
        $(".service-list h2:nth-of-type(3)").attr("id", "plumbing-repairs");
        $(".service-list h2:nth-of-type(4)").attr("id", "new-construction");
        $(".req-container").stop();
    }

    if(window.matchMedia('(max-width: 1365px)').matches){

        if($("div .review-container").length){
            let reviewContainer = $(".index h2").offset().top;
            $(window).scroll(function(){
                if($(window).scrollTop() + $(window).height() > reviewContainer){
                    $("div .review-container").fadeTo(2000, 1);
                }
            });
        }
    }

    $(".appointment-buttons button:last-of-type").click(function(){
        $("form").slideToggle("slow");
    });

    if(window.matchMedia('(min-width: 1024px)').matches){

        $(window).scroll(function () { 
            if($(".service-list h2:nth-of-type(1)").length){
                let headingSpot = $(".service-list h2:nth-of-type(1)").offset().top;
                if($(window).scrollTop() > headingSpot){
                    $(".quick-links").css("opacity", "0.3");
                }
                if($(window).scrollTop() < headingSpot){
                    $(".quick-links").css("opacity", "1");
                }
            }
        });
    }
});