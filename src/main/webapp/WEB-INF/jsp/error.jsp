<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<jsp:include page="header.jsp" />

<!--   Icon Section   -->
<div class="container">
    <div class="row text-center">
        <div class="col s12 m12">
            <div class="icon-block ">
                <h2 class="text-center light-blue-text"><i class="small material-icons ">error</i></h2>
                <h5 class="text-center">Upss Algo Salió mal :( </h5>

                <p class="light">${error} ${status}</p>
                <p class="light">${message}</p>
                <img width="40%" src="/css/wrong.png"> </img>
            </div>
        </div>
    </div>
</div>
<jsp:include page="footer.jsp" />