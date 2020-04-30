FROM alpine as build

RUN apk --update --no-cache add \
    g++ \
    make

WORKDIR /app

COPY . .

RUN make build

FROM scratch

COPY --from=build /lib /lib
COPY --from=build /usr/lib /usr/lib
COPY --from=build /app/echoargs /app/echoargs

ENTRYPOINT ["/app/echoargs"]