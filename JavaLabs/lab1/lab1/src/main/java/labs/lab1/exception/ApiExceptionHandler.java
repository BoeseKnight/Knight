package labs.lab1.exception;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.context.request.WebRequest;

import java.time.ZoneId;
import java.time.ZonedDateTime;
@ControllerAdvice
public class ApiExceptionHandler {
    @ExceptionHandler(value={RequestException.class})
    public ResponseEntity<Object> handleRequestException(RequestException ex){
        HttpStatus badRequest = HttpStatus.BAD_REQUEST;
        Exception exception = new Exception(ex.getMessage(), badRequest, ZonedDateTime.now(ZoneId.of("Z")));
        return new ResponseEntity<>(exception, badRequest);
    }


}
